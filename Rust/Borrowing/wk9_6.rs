fn main() {
    let s = String::from("hello");

    myprint(&s);

    println!("{}",s);
}

fn myprint(t : &String) {
    println!("{}",t);
    // no need return because it is borrowing!
}
