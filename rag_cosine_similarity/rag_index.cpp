#include "rag_index.hpp"

TextEmbedder::TextEmbedder(int dim_count, int seed_val) {
    dimensions = dim_count;
    base_seed = seed_val;
}

std::vector<float> TextEmbedder::embed(const std::string & input_text) {

    // I don't fully understand this yet, random number generator instead of ML model
    size_t text_hash = std::hash<std::string>{}(input_text);
    uint32_t seed = (uint32_t)(text_hash ^ base_seed);
    std::mt19937 generator(seed);
    std::normal_distribution<float> distribution(0.0f, 1.0f);
    std::vector<float> vector_data = {};
    float sum_of_squares = 0.0f;

    for (int i = 0; i < dimensions; i++) {
        float val = distribution(generator);
        vector_data.push_back(val);
        sum_of_squares += val * val;
    }

    // Normalize vector to length of 1.0
    float norm = std::sqrt(sum_of_squares);
    if (norm > 0.0f) {
        for (auto & val : vector_data) {
            val = val / norm;
        }
    }

    return vector_data;
}

VectorIndex::VectorIndex(int dimensions, int seed_val) 
    : embedder(dimensions, seed_val) {
}

void VectorIndex::add_document(const std::string & doc_id, const std::string & text) {
    Document doc;
    doc.doc_id = doc_id;
    doc.text = text;
    doc.embedding = embedder.embed(text);
    documents.push_back(doc);
}

float VectorIndex::cosine_similarity(const std::vector<float> & vec_one, const std::vector<float> & vec_two) {
    if (vec_one.size() != vec_two.size()) {
        return 0.0f;
    }

    if (vec_one.empty()) {
        return 0.0f;
    }

    float dot_product = 0.0f;
    float norm_one = 0.0f;
    float norm_two = 0.0f;

    for (int i = 0, len = (int)vec_one.size(); i < len; i++) {
        dot_product += vec_one[i] * vec_two[i];
        norm_one += vec_one[i] * vec_one[i];
        norm_two += vec_two[i] * vec_two[i];
    }

    if (norm_one <= 0.0f || norm_two <= 0.0f) {
        return 0.0f;
    }

    float similarity = dot_product / (std::sqrt(norm_one) * std::sqrt(norm_two));

    if (similarity > 1.0f) {
        return 1.0f;
    }
    else if (similarity < -1.0f) {
        return -1.0f;
    }

    return similarity;
}

std::vector<SearchResult> VectorIndex::search(const std::string & query_text, int top_k) {
    if (documents.empty()) {
        return {};
    }

    if (top_k <= 0) {
        return {};
    }

    std::vector<float> query_vector = embedder.embed(query_text);
    std::vector<SearchResult> scored_results = {};

    for (auto & doc : documents) {
        SearchResult result;
        result.doc_id = doc.doc_id;
        result.text = doc.text;
        result.score = cosine_similarity(query_vector, doc.embedding);

        scored_results.push_back(result);
    }

    // Sort highest score first
    std::sort(scored_results.begin(), scored_results.end(), [](const SearchResult & first, const SearchResult & second) {
        return first.score > second.score;
    });

    std::vector<SearchResult> output = {};
    for (int i = 0, len = (int)scored_results.size(); i < len && i < top_k; i++) {
        output.push_back(scored_results[i]);
    }

    return output;
}

int VectorIndex::size() {
    return (int)documents.size();
}

void VectorIndex::clear() {
    documents.clear();
}
