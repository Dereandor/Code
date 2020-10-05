fn main() {
    let message = "Hello & welcome < user >".to_string();
    println!("{}", message);
    println!("{}", replace(message));
}

fn replace(string: std::string::String) -> std::string::String{
    let replace_amp = string.replace("&", "&amp");
    let replace_lt = replace_amp.replace("<", "&lt");
    let replace_gt = replace_lt.replace(">", "&gt");
    return replace_gt;
}
