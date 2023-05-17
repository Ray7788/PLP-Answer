fn main() {
    let s = String::from("hello");

    //transfer ownership of the value owed by s to x
    //rust calls this "moving" the value
    let x = s;

    //use x
    println!("{}",x);

    //when we try to use the value in s, we get an error because the variable s
    //no longer owns this value, so it will be FAILED!!
    println!("{}",s);
}
