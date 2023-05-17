fn main() {
    let s = String::from("hello");

    // & is for borrowing
    // if we borrow the value instead, we can still use the original
    let x = &s;
    let y = &s;

    // output works well
    println!("{}",x);
    println!("{}",y);
    println!("{}",s);
}
