// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"
#include <cinder/app/App.h>
#include <cinder/CinderImGui.h>
#include "iostream"



namespace myapp {

using cinder::app::KeyEvent;

MyApp::MyApp() { }

void MyApp::setup() {
  ImGui::Initialize();
}

void MyApp::update() {
}

void MyApp::draw() {
    if (load_previous) {
      LoadOldManager();
    }

    if (load_new) {
      LoadNewManger();
    }

    if (load_manager) {
      LoadUnlockedManager();
    }

    if (load_info) {
      ShowInfo();
    }
}

void MyApp::keyDown(KeyEvent event) { }

void MyApp::LoadOldManager() {
  LoadCorrectSizeAndPos();
  if (ImGui::Begin("Load", &active)) {
    ImGui::InputText("Provide Password", input_pass,IM_ARRAYSIZE(master_pass));
    if (ImGui::Button("New Manager")) {
      load_previous = false;
      load_new = true;
    }
    ImGui::SameLine();
    if (ImGui::Button("Done")) {

      std::string user_input = std::string(input_pass);
      std::string hashed_user_input = maker.StringToShaGenerate(user_input);
      std::ifstream file("C:\\Users\\Icely\\Desktop\\Cinder-master"
                         "\\my-projects\\final-project-nahmad31\\assets\\user_file.txt");
      std::string first_line;
      std::getline(file,first_line);

      if (hashed_user_input == first_line) {
        std::ifstream file2("C:\\Users\\Icely\\Desktop\\Cinder-master"
                           "\\my-projects\\final-project-nahmad31\\assets\\user_file.txt");
        std::string encrypted_text;
        maker.GrabKey();
        maker.GrabIV();

        while (std::getline(file,encrypted_text)) {
          if (at_first_line) {
            at_first_line = false;
            continue;
          }
          std::string decrypted_text = maker.decrypt(encrypted_text);

          if (website) {
            maker.websites.push_back(decrypted_text);
            website = false;
            username = true;
            continue;
          }

          if (username) {
            maker.usernames.push_back(decrypted_text);
            username = false;
            password = true;
            continue;
          }

          if (password) {
            maker.passwords.push_back(decrypted_text);
            password = false;
            website = true;
            continue;
          }
        }
        load_previous = false;
        load_manager = true;
      }
    }
    // Early out if the window is collapsed, as an optimization.
    ImGui::End();
  }
}

void MyApp::LoadNewManger() {
  LoadCorrectSizeAndPos();
  if (ImGui::Begin("Creation", &active)) {
      ImGui::InputText("Create master password", master_pass,IM_ARRAYSIZE(master_pass));

    if (ImGui::Button("Done")) {
      maker.GenerateKey();
      maker.GenerateIV();
      std::string master_pass_str = std::string(master_pass);
      std::string sha_hash = maker.StringToShaGenerate(master_pass_str);
      write(sha_hash);
      load_new = false;
      load_previous = true;
    }
    // Early out if the window is collapsed, as an optimization.
    ImGui::End();
  }
}

void MyApp::LoadUnlockedManager() {
  LoadCorrectSizeAndPos();
  if (ImGui::Begin("Unlocked Manager", &active)) {
    ImGui::InputText("Add Website", website_char,IM_ARRAYSIZE(website_char));
    ImGui::InputText("Add Username", username_char,IM_ARRAYSIZE(username_char));
    ImGui::InputText("Add Password", password_char,IM_ARRAYSIZE(password_char));

    if (ImGui::Button("Show Info")) {
      load_manager = false;
      load_info = true;
    }

    if (ImGui::Button("Done")) {
      std::string website_str = std::string(website_char);
      std::string username_str = std::string(username_char);
      std::string password_str = std::string(password_char);

      maker.websites.push_back(website_str);
      maker.usernames.push_back(username_str);
      maker.passwords.push_back(password_str);

      maker.encrypt(website_str);
      maker.encrypt(username_str);
      maker.encrypt(password_str);

    }
    // Early out if the window is collapsed, as an optimization.
    ImGui::End();
  }
}

void MyApp::write(std::string &input) {
  std::ofstream myfile;
  myfile.open(path, std::ios::app);
  if (myfile.is_open()) {
    myfile << input<< '\n';
    myfile.close();
  } else {
    myfile.open("tripod.txt", std::ios::app);
    myfile << input;
    myfile.close();
  }
}

void MyApp::LoadCorrectSizeAndPos() {
  ImGui::SetNextWindowPos(ImVec2(1, 0), ImGuiCond_FirstUseEver);
  ImGui::SetNextWindowSize(ImVec2(797, 798), ImGuiCond_FirstUseEver);
}

void MyApp::ShowInfo() {
  LoadCorrectSizeAndPos();
  if (ImGui::Begin("Information", &active)) {
    for (int i = 0; i < maker.websites.size(); i++) {
      ImGui::Text("%s", maker.websites[i].c_str());
      ImGui::Text("%s", maker.usernames[i].c_str());
      ImGui::Text("%s", maker.passwords[i].c_str());
      ImGui::NewLine();
    }
    if (ImGui::Button("Done")) {
      load_info = false;
      load_manager;
    }
    // Early out if the window is collapsed, as an optimization.
    ImGui::End();
  }

}
}  // namespace myapp
