#include "rag_index.hpp"
#include <iostream>
#include <iomanip>

int main() {
    int pass = 0;
    int total = 0;

    VectorIndex index(128, 42);

    // Test 1: Cosine similarity on identical vectors
    {
        total++;
        std::vector<float> vec_one = {1.0f, 2.0f, 3.0f};
        float sim = index.cosine_similarity(vec_one, vec_one);
        bool ok = std::abs(sim - 1.0f) < 1e-4f;
        pass += ok;
        std::cout << (ok ? "PASS" : "FAIL") << "  cosine_similarity(identical) expected 1.0, got " << sim << "\n";
    }

    // Test 2: Cosine similarity on opposite vectors
    {
        total++;
        std::vector<float> vec_one = {1.0f, 2.0f, 3.0f};
        std::vector<float> vec_two = {-1.0f, -2.0f, -3.0f};
        float sim = index.cosine_similarity(vec_one, vec_two);
        bool ok = std::abs(sim - (-1.0f)) < 1e-4f;
        pass += ok;
        std::cout << (ok ? "PASS" : "FAIL") << "  cosine_similarity(opposite) expected -1.0, got " << sim << "\n";
    }

    // Test 3: Cosine similarity on orthogonal vectors
    {
        total++;
        std::vector<float> vec_one = {1.0f, 0.0f, 0.0f};
        std::vector<float> vec_two = {0.0f, 1.0f, 0.0f};
        float sim = index.cosine_similarity(vec_one, vec_two);
        bool ok = std::abs(sim - 0.0f) < 1e-4f;
        pass += ok;
        std::cout << (ok ? "PASS" : "FAIL") << "  cosine_similarity(orthogonal) expected 0.0, got " << sim << "\n";
    }

    // Test 4: Embedder determinism (same string -> exact same embedding)
    {
        total++;
        TextEmbedder embedder(64, 100);
        std::string query = "What is retrieval augmented generation?";
        auto emb_one = embedder.embed(query);
        auto emb_two = embedder.embed(query);

        bool identical = (emb_one.size() == 64 && emb_two.size() == 64);
        for (int i = 0; i < 64 && identical; i++) {
            if (emb_one[i] != emb_two[i]) {
                identical = false;
            }
        }
        pass += identical;
        std::cout << (identical ? "PASS" : "FAIL") << "  embedder determinism on repeated text\n";
    }

    // Test 5: Embedder unit norm (L2 norm is 1.0)
    {
        total++;
        TextEmbedder embedder(64, 100);
        auto emb = embedder.embed("sample text");
        float sum_of_squares = 0.0f;
        for (auto & val : emb) {
            sum_of_squares += val * val;
        }
        float norm = std::sqrt(sum_of_squares);
        bool ok = std::abs(norm - 1.0f) < 1e-4f;
        pass += ok;
        std::cout << (ok ? "PASS" : "FAIL") << "  embedder unit normalization expected 1.0, got " << norm << "\n";
    }

    // Test 6: Document insertion and size
    {
        total++;
        index.clear();
        index.add_document("doc_rag", "Retrieval-augmented generation combines search and LLMs.");
        index.add_document("doc_cpp", "Modern C++ emphasizes value semantics and RAII.");
        index.add_document("doc_chess", "The Sicilian Defense is an aggressive chess opening.");

        bool ok = (index.size() == 3);
        pass += ok;
        std::cout << (ok ? "PASS" : "FAIL") << "  index.size() expected 3, got " << index.size() << "\n";
    }

    // Test 7: Similarity search ranking (exact match returns top score)
    {
        total++;
        std::string query = "Retrieval-augmented generation combines search and LLMs.";
        auto results = index.search(query, 2);

        bool ok = (results.size() == 2 && results[0].doc_id == "doc_rag" && std::abs(results[0].score - 1.0f) < 1e-4f);
        pass += ok;
        std::cout << (ok ? "PASS" : "FAIL") << "  search ranking top match=" << (results.empty() ? "none" : results[0].doc_id)
                  << " score=" << (results.empty() ? 0.0f : results[0].score) << "\n";
    }

    // Test 8: Empty index search
    {
        total++;
        VectorIndex empty_index(64, 42);
        auto results = empty_index.search("query", 3);
        bool ok = results.empty();
        pass += ok;
        std::cout << (ok ? "PASS" : "FAIL") << "  search on empty index returns empty vector\n";
    }

    std::cout << pass << "/" << total << " tests passed\n";
    return 0;
}
