# Password Protector

[![license](https://img.shields.io/badge/license-MIT-green)](LICENSE)
[![docs](https://img.shields.io/badge/docs-yes-brightgreen)](docs/README.md)

Read [this document](https://cliutils.gitlab.io/modern-cmake/chapters/basics/structure.html) to understand the project
layout.

**Author**: Nashwaan Ahmad - [`nahamd31@illinois.edu`](mailto:nahmad31@illinois.edu)

Author: Nashwaan Ahmad

The project I want to work on is a simple password manager. This password manager will keep track of passwords a user inputs and their respective usernames. The only background I have with password managers is that I use them. I have never tried to implement them in any language so this will be a learning experience for me. This project is interesting to me because I want to go into a field that is security related, and me researching about this topic could be a gateway into cryptography. That I will have at the minimum a rough sense on how professional password managers work and operate.

Libraries I will possibly using will be Bcrypt, Botan, or even Crypto++. These will be used to implement algorithms that I have not created since they are advanced topics in the field of CS. Links to the libraries: http://bcrypt.sourceforge.net/, https://botan.randombit.net/, https://github.com/weidai11/cryptopp.

The plan is by the first week I will try to get the user features down such as putting a password and usernames down. Into the second week I will try to create a GUI so the user does not have to do this through a terminal. Then I will try to implement a way to encrypt the file as to not allow prying eyes to easily see what is inside what will possibly be a text file stored locally on the user’s machine. “Stretch” features might be that once a password is copied it will be cleared from the user’s clipboard after a certain amount of time, say 10 seconds.
