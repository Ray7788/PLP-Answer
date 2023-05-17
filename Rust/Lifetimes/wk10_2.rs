fn main() {
    let a = vec![6,5];
    println!("{}",a.len());

    // defined out of scope, so could be live longer than y inside
    let x: &Vec<i32>;

    // new scope 使用{}来定义一个作用域（scope），也被称为代码块（code block）。作用域定义了一段代码的边界，它可以用于控制变量的可见性和生命周期。
    {
     let b = vec![7,8,9];
     let y: &Vec<i32>;
     (x,y) = (&a,&b);
     println!("{}",y.len());
    }

    print!("{}",x.len());
}

// 生命周期（行数） 
// a: 2-15
// b: 9-12