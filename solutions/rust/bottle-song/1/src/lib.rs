const NUMBER_STRINGS: [&str; 11] = [
    "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
];

pub fn verse(num_bottles: u32) -> String {
    match num_bottles {
        x if x > 2 => {
            let index = x as usize;
            format!(
                "{num} green bottles hanging on the wall,\n\
                {num} green bottles hanging on the wall,\n\
                And if one green bottle should accidentally fall,\n\
                There'll be {next} green bottles hanging on the wall.",
                num = NUMBER_STRINGS[index],
                next = NUMBER_STRINGS[index - 1].to_lowercase(),
            )
        }
        2 => "Two green bottles hanging on the wall,\n\
             Two green bottles hanging on the wall,\n\
             And if one green bottle should accidentally fall,\n\
             There'll be one green bottle hanging on the wall."
            .to_string(),
        1 => "One green bottle hanging on the wall,\n\
             One green bottle hanging on the wall,\n\
             And if one green bottle should accidentally fall,\n\
             There'll be no green bottles hanging on the wall."
            .to_string(),
        _ => {
            unimplemented!()
        }
    }
}
pub fn recite(start_bottles: u32, take_down: u32) -> String {
    let range = (start_bottles - take_down + 1..=start_bottles).rev();
    let verses: Vec<String> = range.map(|num_bottles| verse(num_bottles)).collect();
    verses.join("\n\n")
}
