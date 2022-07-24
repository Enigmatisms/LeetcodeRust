type Link = Option<Box<ListNode>>;
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
  pub val: i32,
  pub next: Link
}

fn main() {
  let a = String::from("123456");
  for x in a.as_bytes() {
    println!("{}", *x - 48);
  }
  println!("{}", 5 - &2);
}
