# SecureBytes

SecureBytes is a simple file encryption and decryption program written in C++. It allows users to encrypt and decrypt files using a numeric key.

## Features

- Encrypt any file using a user-provided numeric key.
- Decrypt previously encrypted files using the same numeric key.
- Supports various file types (e.g., .png, .pdf, .txt).

## How It Works

- **Encryption**: The program reads the file byte by byte, adds the numeric key to each byte, and writes the modified byte to a new file with the suffix `-encrypt.enc`.
- **Decryption**: The program reads the encrypted file byte by byte, subtracts the numeric key from each byte, and writes the original byte to a new file with the suffix `-decrypt` followed by the original file extension.

## Run the Program

### Follow the Menu

- Press 1 to Encrypt a file.
- Press 2 to Decrypt a file.
- Press 3 to Exit the program.

### Example commands during the run:

- **For encryption:** Enter the file name -> a numeric key (password).
- **For decryption:** Enter the encrypted file name -> the same numeric key used for encryption, -> the original file extension.
