#ifndef RAG_INDEX_HPP
#define RAG_INDEX_HPP

#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <random>

const int SEED = 0;
const int DIM = 128;

struct SearchResult {
    std::string doc_id;
    std::string text;
    float score = 0.0f;
};

struct Document {
    std::string doc_id;
    std::string text;
    std::vector<float> embedding;
};

class TextEmbedder {
    private:
        int dimensions = DIM;
        int base_seed = SEED;

    public:
        TextEmbedder(int dim_count = DIM, int seed_val = SEED);
        std::vector<float> embed(const std::string & input_text);
};

class VectorIndex {
    private:
        TextEmbedder embedder;
        std::vector<Document> documents;

    public:
        VectorIndex(int dimensions = DIM, int seed_val = SEED);
        void add_document(const std::string & doc_id, const std::string & text);
        float cosine_similarity(const std::vector<float> & vec_one, const std::vector<float> & vec_two);
        std::vector<SearchResult> search(const std::string & query_text, int top_k);
        int size();
        void clear();
};

#endif // RAG_INDEX_HPP
