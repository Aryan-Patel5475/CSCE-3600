{
    i = $1
    j = $1
    if (i == 0) {
        i = 0
        printf "%s\t%s\n", j, i
    }
    
    if (i > 0) {
        while ( i > 360) {
            i = i - 360
        }
        printf "%s\t%s\n", j, i
    }
    
    if (i < 0) {
        while (i < 0) {
            i = i + 360
        }
        printf "%s\t%s\n", j, i
    }
    
}
