fn main() {
    let i = 10;
    let j = i;

    //need to declare i with 'let mut'
    // or we can use let i = 11;  "shadowing" 
    i = 11;

    println!("{}",i);
    println!("{}",j);
}

// error[E0384]: cannot assign twice to immutable variable `i`
