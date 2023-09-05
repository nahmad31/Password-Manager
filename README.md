# Password Protector

[![license](https://img.shields.io/badge/license-MIT-green)](LICENSE)
[![docs](https://img.shields.io/badge/docs-yes-brightgreen)](docs/README.md)

Read [this document](https://cliutils.gitlab.io/modern-cmake/chapters/basics/structure.html) to understand the project
layout.

**Author**: Nashwaan Ahmad - [`nahamd31@illinois.edu`](mailto:nahmad31@illinois.edu)

Author: Nashwaan Ahmad

This project is a simple password manager with a graphical user interface. This password manager will only keep track of passwords and their respective usernames. Having no previous experience programming a password manager, this will be a learning experience for me. This project was interesting to create because I want to implement a secure password manager and to learn the difficulties that go with creating one, such as how to encrypt the passwords and store the keys as to not leak them. That through this project I will gain at minimum a rough sense on how professional password managers work and operate.

The library I have used to encrypt is the Crypto++ (https://github.com/weidai11/cryptopp). These will be used to implement algorithms that I have not created since they are advanced topics in the field of CS. 

# Features

Password Protector features a graphical user interface where the user can input username with the respective passwords. There is also a terminal user interface if one wishes to use that in place of the GUI. The usernames and passwords will then be encrypted with AES256 and the user will be given a key and a IV file to keep hidden and used to unlock the password manager and decrypt the usernames and passwords into memory. Future features include being able to copy passwords into a user's clipboard and after a certain period of time clearing it out, which can be adjusted according to the user. 
