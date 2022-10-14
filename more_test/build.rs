extern crate cc;

fn main() {
    cc::Build::new()
        .flag("-std=c++17")
        .file("src/enum_class.cc")
        .flag("-O3")
        .compile("libenum_class.a");
    println!("cargo:rustc-flags=-l dylib=stdc++");

    // Maybe two Build instances solves the problem
}
