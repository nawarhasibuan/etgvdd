# Competitive Programming Solutions

Repo ini berisi kumpulan solusi soal-soal kompetisi CP yang ditulis dalam bahasa C++.

## Struktur Folder

- `src/templates/` - Template kode C++ yang sering digunakan
- `src/contests/` - Solusi dari berbagai platform (AtCoder, Codeforces, CSES, local contest)
- `tests/` - input dan expected output
- `notes/` - Catatan, snippet, dan referensi pribadi
- `bin/`- Hidden folder tempat executable file

## Cara Compile & Run

```bash
g++ -std=c++17 -O2 -Wall A.cpp -o A
./bin/A < input.txt
```

Atau jika tidak ada input file:

```bash
./bin/A
```

Menggunakan script yang tersedia di repo ini

```bash
./cp <command> <option>
```

Daftar command/perintah yang tersedia

- `compile` untuk kompilasi satu file
- `build` untuk kompilasi semua file \*.cpp yang belum di kompilasi atau ada perubahan
- `clean` untuk membersihkan executable file di folder`bin/`
- `run` untuk menjalankan hasil kompilasi satu program
- `grader` untuk mencocokkan output program dengan expected output yang ada di folder expected

command `compile`, `run`, dan `grader` harus disertai `<option>` format yang sesuai dengan tempat penyimpanan program. Pastikan file `input` tersedia untuk command `run`, dan `input` dan `expected` untuk comman `grader`

`<contest>/<problemset>/<problem>`. contoh `osn/osp2025/A`

Contoh penggunaan

```bash
./cp grader osn/osp2025/A
```

## Code Format

install clang-format melalui link [llvm](https://releases.llvm.org/download.html) dan extensions clang format pada vscode

## TIPS

- Gunakan input.txt dan output.txt untuk testing lokal.
- Tambahkan snippet baru ke `templates/` jika sering dipakai.
- Simpan insight atau pembahasan tricky problem di README.md per folder kontes.

## 📞 Contact Me

### 📬 Email

[![Email](https://img.shields.io/badge/Gmail-panawarinformatika%40gmail.com-D14836?style=for-the-badge&logo=gmail&logoColor=white)](mailto:panawarinformatika@gmail.com)

### 📞 Phone

[![Phone](https://img.shields.io/badge/Phone-%2B62%20813--9529--5177-brightgreen?style=for-the-badge)](tel:+6281395295177)

### 💬 WhatsApp

[![WhatsApp](https://img.shields.io/badge/WhatsApp-Chat-25D366?style=for-the-badge&logo=whatsapp&logoColor=white)](https://wa.me/6281395295177)

---

Feel free to fork, clone, or discuss.

Happy Coding! 🚀
