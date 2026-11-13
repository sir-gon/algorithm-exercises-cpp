#include <exercises/hackerrank/interview_preparation_kit/dictionaries_and_hashmaps/ctci_ransom_note.hpp>
#include <iostream>
#include <new>

/**
 * @link Problem definition
 * [[docs/hackerrank/interview_preparation_kit/dictionaries_and_hashmaps/ctci-ransom-note.md]]
 */

namespace hackerrank::interview_preparation_kit::dictionaries_and_hashmaps {

const unsigned int __HASH_BUCKETS__ = 256;
const unsigned int __WORD_COUNT_START__ = 1;

typedef struct WordCount {
  string word;
  int count = 0;
  struct WordCount *next = nullptr;
} WordCount;

static int hash_function(const string &word) {
  if (word.empty()) {
    return 0;
  }

  // Normalize the first byte to the unsigned range [0,255]. Using a signed char
  // directly makes the bucket index negative for UTF-8 bytes above 127 and is
  // undefined behavior on some platforms (Linux/Windows/ASan can then crash).
  return static_cast<int>(static_cast<unsigned char>(word[0])) %
         __HASH_BUCKETS__;
}

static WordCount *find_word_count(WordCount *bucket, const string &word) {
  while (bucket != nullptr) {
    if (bucket->word == word) {
      return bucket;
    }
    bucket = bucket->next;
  }

  return nullptr;
}

static void free_word_count_buckets(WordCount *buckets[__HASH_BUCKETS__]) {
  for (int i = 0; i < __HASH_BUCKETS__; ++i) {
    WordCount *current = buckets[i];
    while (current != nullptr) {
      WordCount *next = current->next;
      current->~WordCount();
      free(current);
      current = next;
    }
  }
}

static bool checkMagazineCompute(const vector<string> &magazine,
                                 const vector<string> &note) {
  // build dictionary from magazine
  WordCount *buckets[__HASH_BUCKETS__] = {nullptr};

  for (int i = 0; i < magazine.size(); i++) {
    const string word = magazine[i];
    int hash = hash_function(word);
    WordCount *current = find_word_count(buckets[hash], word);

    if (current != nullptr) {
      current->count++;
      continue;
    }

    void *memory = tools::getMemoryAllocator()(sizeof(WordCount));
    if (memory == nullptr) {
      // Handle memory allocation failure
      free_word_count_buckets(buckets);
      return false;
    }

    buckets[hash] =
        new (memory) WordCount{word, __WORD_COUNT_START__, buckets[hash]};
  }

  // Search words in the note and check if they exist in the magazine dictionary
  for (int i = 0; i < note.size(); i++) {
    const string word = note[i];
    int hash = hash_function(word);
    WordCount *current = find_word_count(buckets[hash], word);

    if (current == nullptr || current->count <= 0) {
      free_word_count_buckets(buckets);
      return false;
    }
    current->count--;
  }

  free_word_count_buckets(buckets);
  return true;
}

const string checkMagazineText(const vector<string> &magazine,
                               const vector<string> &note) {
  if (!checkMagazineCompute(magazine, note)) {
    return __RANSOM_NOTE_NO__;
  } else {
    return __RANSOM_NOTE_YES__;
  }
}

void checkMagazine(vector<string> magazine, vector<string> note) {
  std::cout << checkMagazineText(magazine, note) << std::endl;
}

} // namespace hackerrank::interview_preparation_kit::dictionaries_and_hashmaps
