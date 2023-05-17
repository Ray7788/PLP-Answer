fn main() {
    let mut s = vec![4,5,6];

    s.push(7);

    let x = & s;

    //this line is fine
    println!("{}",s.len());

    let t = &mut s;

    t.push(8);

    println!("{}",t.len());
    println!("{}",s.len());

    //this line is not, because it
    //means the mutable borrow of s to x
    //happens at the same time as the
    //mutable borrow to t
    //and we can't have a mutable borrow at
    //the same time as another borrow
    println!("{}",x.len());
}
