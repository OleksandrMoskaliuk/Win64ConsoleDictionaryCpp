#pragma once
#ifndef DICTIONARY_H
#define DICTIONARY_H

/* lightweight selfmade data struct */
#include "my_list/MyList.h"
#include <vector>
namespace my_dictionary {
// interface:
// push word (string(word), translation() category() usage())
// delete word by name
// delete word by number
// dictionary info
//				words amount
//				print all words
//
// fstream -> writing and reading
//     ifstream -> reading from file
//     ofstreeam -> writing into file
//
//
// for fstream, this moves the file position pointer (both put and get)
// s.seekp(0);

// 1. word: train
//    translation: ����
// 
//    category: items
//    usages: ...
// 2. word:
//
// file >> variable // read
// file << variable // write
//
struct Word {
  std::string word;
  std::string translation;
  std::string category;
  std::string example;
};

class MyDictionary  {
 public:
  MyDictionary();
  ~MyDictionary() { save_to_file(); }
  void MainLoop();
  const char* filename = "dctionary";
  const char* ImportFileNameEN = "ImportEN";
  const char* ImportFileNameUA = "ImportUA";
  void show_dictionary();
  void read();

 private:
 my_list::List<Word> Data;
 const int history_buffer = 500;
 std::string history;
 bool check_if_exist(std::string new_word);
 bool load();
 bool Import();
 bool save_to_file();
 bool save_word(Word &new_word);
 bool edit_word(long int index);
 void print_history();
 void add_to_history(std::string str);
 void change_cursor_xy(int x, int y);
 bool test_yourself();
 void shake_word_menu(std::vector<std::string>& word_menu, int times_to_shake);
 // next method only for test_yourself function;
 void tets_yourself_word_checker(bool en_or_ua, bool& generate,
                                 bool& printonce, int menu_cursor,
                                 Word selected_word_node,
                                 std::vector<std::string>& word_menu);

public:
 my_list::List<Word>* GetData();
};  // class MyDictionary : public my_sfml::DctCore

};  // namespace my_dictionary

#endif  // !DICTIONARY_H
