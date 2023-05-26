# Class Template Generator

## Overview

The Class Template Generator is a command-line program that creates empty templates for C++ classes. It automatically generates both `.cpp` and `.hpp` files adhering to the Orthodox canonical class form and follows the Google C++ Style Guide. Additionally, it sets up an alias in your `.zshrc` file, allowing you to execute the program from anywhere using the `template` command.

## Features

- Automatically creates empty C++ class templates in the Orthodox canonical class form.
- Generates both `.cpp` and `.hpp` files following the Google C++ Style Guide.
- Sets up an alias in your `.zshrc` file for convenient execution.

## Prerequisites

To use the Class Template Generator, ensure that you have the following software installed on your system:

- C++ compiler (GCC or Clang)
- Zsh shell (for automatic alias setup)

## Installation

1. Clone this repository to your local machine:
```
git clone https://github.com/fsandel/template template
```

2. Navigate to the project directory:

```
cd template
```

3. Build and install the program using the provided Makefile:

```
make install
```


This will create an alias named "template" that points to the executable file of the Class Template Generator.

## Usage

Once the installation is complete, you can generate class templates by executing the following command in your terminal:

```
template ClassName
```

Replace `ClassName` with the desired name for your C++ class.

This command will create two files in the current directory: `ClassName.cpp` and `ClassName.hpp`, containing the empty class template in accordance with the Orthodox canonical class form and Google C++ Style Guide.

## Example

Let's assume you want to create a class called `MyClass`. To generate the class template, run the following command:

```
template MyClass
```

This will create `MyClass.cpp` and `MyClass.hpp` files in the current directory, both formatted correctly according to the Orthodox canonical class form and Google C++ Style Guide.

## License

This project is licensed under the [MIT License](https://opensource.org/license/mit/).

## Contributing

Contributions are welcome! If you find any issues or have suggestions for improvements, please open an issue or submit a pull request on the [GitHub repository](https://github.com/fsandel/template).

## Acknowledgements

The Class Template Generator was inspired by the need for a quick and standardized way to create empty C++ class templates. It follows the guidelines provided by the Google C++ Style Guide to ensure consistent and readable code.

## Contact

For any questions or inquiries, feel free to reach out to the project maintainer at [florian@sandel.email](mailto:florian@sandel.email).

Happy coding!
