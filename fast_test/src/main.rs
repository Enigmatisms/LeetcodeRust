type Link = Option<Box<ListNode>>;
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
  pub val: i32,
  pub next: Link
}

fn main() {
    let mut a = ListNode{val:0, next:None};
    let mut b = Some(Box::new(ListNode{val:1, next:Some(Box::new(a))}));
    let mut c = b.clone();
    c.as_mut().map(|inner| {
        inner.next.as_mut().map(|a_val| {
            a_val.val = 2;
        });
    });
    println!("{}", b.as_ref().unwrap().next.as_ref().unwrap().val);
    println!("{}", c.as_ref().unwrap().next.as_ref().unwrap().val);
}
