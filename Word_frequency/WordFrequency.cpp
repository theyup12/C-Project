
#include "WordFrequency.h"
#include "sanitize.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
using std::string;
// default constructor
WordFrequency::WordFrequency() {}
// read the single word from the file, and put it into the the hashtable
void WordFrequency::readIn(const string &filename) {
  // open the file
  std::ifstream infile(filename);
  // variable that take line of word from the file
  string line;
  // variable that take the single word from the file
  string word;
  // using the while loop to get the line from the file
  while (std::getline(infile, line)) {
    std::stringstream lineStream(line);
    // take the single word from the line
    while (lineStream >> word) {
      // helper function that take out the special punctuation
      sanitize(word);
      // use to take the punctuation from the word
      char punc = word[word.size() - 1];
      if (punc == '.' || punc == '?' || punc == '!') {
        word = word.substr(0, word.size() - 1);
        // add number of frequent word to the value
        wordmap[word]++;
      } else {
        wordmap[word]++;
      }
    }
  }
} // add words from file to hash table
// return the number of unique words
size_t WordFrequency::numberOfWords() { return wordmap.size(); }
// return the number of occurrences of the given word
size_t WordFrequency::wordCount(const string &word) { return wordmap[word]; }
// return the most frequent word
string WordFrequency::mostFrequentWord() {
  string key = "";
  int value = 0;
  std::unordered_map<string, int>::iterator it;
  // to get the max of the word
  for (it = wordmap.begin(); it != wordmap.end(); it++) {
    if (it->second > value) {
      value = it->second;
      key = it->first;
    }
  }
  return key;
}
size_t WordFrequency::maxBucketSize() {
  size_t n = wordmap.bucket_count();
  int val = wordmap.bucket_size(0);
  for (int i = 0; i < n; i++) {
    if (val < wordmap.bucket_size(i)) {
      val = wordmap.bucket_size(i);
    }
  }
  // return the size of the bucket
  return val;
}
