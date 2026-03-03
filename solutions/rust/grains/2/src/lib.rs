pub fn square(s: u32) -> u64 {
    match s {
        1 => 1,
        _ => square(s - 1) * 2
    }
}

pub fn total() -> u64 {
    (1..=64).map(square).sum()
}
