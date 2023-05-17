fn main() {
    let mut s = String::from("hello");

    s.push_str(" world!");

    // immutable borrow
    let x = & s;

    //this line is fine because no modify
    println!("{}",x);

    let t = &mut s;

    t.push_str(" And universe!");

    println!("{}",t);
    println!("{}",s);

    //this line is not, because it
    //means the mutable borrow of s to x
    //happens at the same time as the
    //mutable borrow to t
    //and we can't have a mutable borrow at
    //the same time as another borrow
    println!("{}",x);
    // println!("{}",x);不能在 let t = &mut s;之后使用

}
