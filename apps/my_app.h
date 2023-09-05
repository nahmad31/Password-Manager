// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <cinder/app/App.h>
#include <imgui/imgui.h>
#include <fstream>
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include "iostream"
#include "mylibrary/encrypt.h"


namespace myapp {

class MyApp : public cinder::app::App {
 public:
  const char* path = "C:\\Users\\Icely\\Desktop\\Cinder-master\\my-projects\\final-project-nahmad31\\assets\\user_file.txt";
  bool active = true;
  char master_pass[1000] = "";
  char input_pass[1000] = "";

  char website_char[1000] = "";
  char username_char[1000] = "";
  char password_char[1000] = "";

  encrypt::Encryption maker;

  MyApp();
  void setup() override;
  void update() override;
  void draw() override;
  void keyDown(cinder::app::KeyEvent) override;
  void write(std::string &input);
  static void LoadCorrectSizeAndPos();
  void LoadNewManger();
  void LoadOldManager();
  void LoadUnlockedManager();
  void ShowInfo();
  bool load_previous = true;
  bool load_new = false;
  bool load_manager = false;
  bool load_info = false;

  bool at_first_line = true;

  bool website = true;
  bool username = false;
  bool password = false;

};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
