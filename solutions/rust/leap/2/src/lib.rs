pub fn is_leap_year(year: u64) -> bool {
    match (
        year.is_multiple_of(4),
        year.is_multiple_of(100),
        year.is_multiple_of(400),
    ) {
        (_, _ , true) => true,
        (_, true , _) => false,
        (true, _ , _) => true,
        _ => false
    }
}
