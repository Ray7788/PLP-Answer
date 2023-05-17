fn main() {
    let s = String::from("hello");

    let s = myprint(s);

    // still print data of s
    println!("{}",s);
}

fn myprint(t : String) -> String {
    println!("new t from function {}",t);
    
    // This works but redundant
    // s's ownership isn't changed, a new argument t is generated
    return t;
}
