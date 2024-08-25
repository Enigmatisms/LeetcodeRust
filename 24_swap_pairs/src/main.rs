// Definition for singly-linked list.
type Link = Option<Box<ListNode>>;
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
  pub val: i32,
  pub next: Link
}

pub struct List {
  head: Link,
}

impl List {
  pub fn new() -> Self {
      List { head: None }
  }

  pub fn push(&mut self, elem: i32) {
      let new_node = Box::new(ListNode {
          val: elem,
          next: self.head.take(),
      });

      self.head = Some(new_node);
  }

  pub fn pop(&mut self) -> Option<i32> {
      self.head.take().map(|node| {
          self.head = node.next;
          node.val
      })
  }

  pub fn iter(&self) -> Iter<'_> {
      Iter { next: self.head.as_deref() }
  }
}

pub struct Iter<'a> {
  next: Option<&'a ListNode>,
}

impl<'a> Iterator for Iter<'a> {
  type Item = &'a i32;
  fn next(&mut self) -> Option<Self::Item> {
      self.next.map(|node| {
          self.next = node.next.as_deref();
          &node.val
      })
  }
}

impl Drop for List {
  fn drop(&mut self) {
      let mut cur_link = self.head.take();
      while let Some(mut boxed_node) = cur_link {
          cur_link = boxed_node.next.take();
      }
  }
}


pub fn swap_pairs(mut head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
    let mut wrap_ptr = head.take();
    let mut head_set: bool = false;
    let mut last_node:Option<Box<ListNode>>  = wrap_ptr.clone();
    // TODO: previous ptr
    while let Some(mut ptr) = wrap_ptr.take() {
        // [k] [k+1] [k+2] ...
        if let Some(_) = &ptr.next {            // this node has next
            // ptr holds the ref to [k], wrap_ptr refs to [k+1]
            wrap_ptr = ptr.next.take();
            last_node = wrap_ptr.take().and_then(|mut inner| {
              ptr.next = inner.next.take();
              inner.next = Some(ptr);
              if head_set == false {
                head = Some(inner.clone());
                head_set = true;
              }
              last_node.as_mut().and_then(|last_inner|{
                let next = inner.next.take();
                last_inner.next = Some(inner);
                next
              })
            });
            wrap_ptr = last_node.as_mut().and_then(|inner| {    // correct
              // last_node 是一个Option<Box>， Box的next被移动了，但last_node本身（及其Box）不变
              inner.next.take()
            });
        } else {
          break;
        }
    }
    if head_set == false {
      return wrap_ptr;
    }
    return head;
}

fn main() {
  let mut list = List::new();
  list.push(1);
  list.push(2);
  list.push(3);
  list.push(4);
  list.push(5);
  list.push(6);
  list.push(7);
  for x in list.iter() {
    print!("{}, ", x);
  }
  print!("\n");
  let head = list.head.clone();
  let mut head_ptr = swap_pairs(head);
  while let Some(inner) = head_ptr.take() {
    print!("{}, ", inner.val);
    head_ptr = inner.next;
  }
  print!("\n");
}