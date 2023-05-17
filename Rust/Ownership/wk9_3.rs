fn main() {
    let s = String::from("hello");

    // It will FAIL!
    myprint(s);

    println!("{}",s);
}

// A funtion also transfer the ownership! 
// s is transfered to t in myprint(t : String)
fn myprint(t : String) {
    println!("{}",t);
}
