fn main() {
    let a = String::from("he is a fool");
    let slice = &a[0..2];
    let he: &str = "hes";
    println!("{}", slice == he);
}
