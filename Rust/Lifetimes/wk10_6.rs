// 正确版本 correct version
// If the compiler can’t infer the lifetimes, we have to speciy them, using the <’m> syntax. 
fn nice <'a,'b>(x: &'a Vec<i32>, y: &'b Vec<i32>)
  -> ( &'b Vec<i32>, &'a Vec<i32>) {
    // return order is reversed!!!
    return (y,x);
}

fn main() {
    let a = vec![6,5,];
    println!("{}",a.len());

    let x: &Vec<i32>;
    {
     let b = vec![7,8,9];
     let y: &Vec<i32>;
     (y,x) = nice(&a,&b);
     println!("{}",y.len());
    }

    print!("{}",x.len());
}
