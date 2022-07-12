// Definition for singly-linked list.
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
  pub val: i32,
  pub next: Option<Box<ListNode>>
}

impl ListNode {
  #[inline]
  fn new(val: i32) -> Self {
    ListNode {
      next: None,
      val
    }
  }
}

pub fn swap_pairs(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
    let mut head = head;
    let mut wrap_ptr = head.as_mut();
    while let Some(ptr) = wrap_ptr.take() {
        // [k] [k+1] [k+2] ...
        if let Some(_) = &ptr.next {            // this node has next
            // ptr holds the ref to [k], wrap_ptr refs to [k+1]
            wrap_ptr = ptr.next.as_mut();
            if let Some(inner_ptr) = wrap_ptr.as_mut() {
            }

        }
    }
    None
}

fn main() {

}