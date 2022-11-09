#ifndef _HASH_TABLE_
#define _HASH_TABLE_

#include <cstddef>
#include <utility>
#include <vector>

namespace data_structures {

template <typename Key, typename Value>
class HashTable {
   public:
    HashTable() = delete;
    HashTable(std::size_t capacity)
        : size_(0),
          capacity_(capacity),
          table_(capacity_, std::vector<std::pair<Key, Value>>()) {}
    ~HashTable() = default;

    HashTable(const HashTable&) = default;
    HashTable(HashTable&&) = default;

    HashTable& operator=(const HashTable&) = default;
    HashTable& operator=(HashTable&&) = default;

    bool Empty() const { return (0 == size_); }
    std::size_t Size() const { return size_; }
    std::size_t Capacity() const { return capacity_; }
    float LoadFactor() const {
        return static_cast<float>(size_) / static_cast<float>(capacity_);
    }
    bool Contains(const Key& key) const;
    void Rehash(std::size_t new_capacity);

    Value& operator[](const Key& key);
    void Insert(const Key& key, const Value& val);
    bool Remove(const Key& key);

   private:
    using ValueType = std::pair<Key, Value>;
    using Table = std::vector<std::vector<ValueType>>;

    std::size_t Hash(const Key& key) const {
        return (hasher_(key) % capacity_);
    }

    std::size_t size_;
    std::size_t capacity_;
    Table table_;
    std::hash<Key> hasher_;
};

template <typename Key, typename Value>
bool HashTable<Key, Value>::Contains(const Key& key) const {
    std::size_t bucket = Hash(key);
    for (const auto& kv : table_[bucket]) {
        if (kv.first == key) return true;
    }
    return false;
}

template <typename Key, typename Value>
void HashTable<Key, Value>::Rehash(std::size_t new_capacity) {
    Table new_table = std::vector<std::vector<ValueType>>(
        new_capacity, std::vector<ValueType>());

    for (std::size_t i = 0; i < capacity_; ++i) {
        for (const auto& kv : table_[i]) {
            new_table[Hash(kv.first)].emplace_back(
                std::make_pair(kv.first, kv.second));
        }
    }
    table_ = new_table;
    capacity_ = new_capacity;
}

template <typename Key, typename Value>
Value& HashTable<Key, Value>::operator[](const Key& key) {
    std::size_t bucket = Hash(key);
    for (auto& kv : table_[bucket]) {
        if (kv.first == key) return kv.second;
    }

    table_[bucket].emplace_back(std::make_pair(key, Value()));
    size_++;

    return (*this)[key];
}

template <typename Key, typename Value>
void HashTable<Key, Value>::Insert(const Key& key, const Value& val) {
    if (Contains(key)) {
        (*this)[key] = val;
    } else {
        table_[Hash(key)].emplace_back(std::make_pair(key, val));
        size_++;
    }
}

template <typename Key, typename Value>
bool HashTable<Key, Value>::Remove(const Key& key) {
    std::size_t bucket = Hash(key);
    for (auto it = table_[bucket].begin(); it != table_[bucket].end(); ++it) {
        if (key == it->first) {
            table_[bucket].erase(it);
            return true;
        }
    }
    return false;
}

}  // namespace data_structures

#endif
