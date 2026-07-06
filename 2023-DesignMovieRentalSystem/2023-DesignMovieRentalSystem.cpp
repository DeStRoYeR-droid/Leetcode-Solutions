// Last updated: 06/07/2026, 19:00:10
struct Node {
    int shop, movie, price;
    bool operator<(const Node& other) const {
        if (price != other.price) return price < other.price;
        if (shop != other.shop) return shop < other.shop;
        return movie < other.movie;
    }
};

class MovieRentingSystem {
private:
    unordered_map<long long, Node> byPair;
    unordered_map<int, set<Node>> available;
    set<Node> rented;

    long long key(int shop, int movie){
        return ((long long) shop << 32) ^ movie;
    }

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto& e : entries){
            int shop = e[0], movie = e[1], price = e[2];
            Node node{shop, movie, price};

            byPair[key(shop, movie)] = node;
            available[movie].insert(node);
        }
    }
    
    vector<int> search(int movie) {
        vector<int> result;
        if (available.count(movie) == 0) return result;
        auto& s = available[movie];
        int count = 0;
        for (auto it = s.begin(); it != s.end() && count < 5; ++it, ++count){
            result.push_back(it->shop);
        }
        return result;
    }
    
    void rent(int shop, int movie) {
        long long k = key(shop, movie);
        Node node = byPair[k];
        available[movie].erase(node);
        rented.insert(node);
    }
    
    void drop(int shop, int movie) {
        long long k = key(shop, movie);
        Node node = byPair[k];
        rented.erase(node);
        available[movie].insert(node);   
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> result;
        int count = 0;
        for (auto it = rented.begin(); it != rented.end() && count < 5; ++it, ++count){
            result.push_back({it->shop, it->movie});
        }
        return result;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */