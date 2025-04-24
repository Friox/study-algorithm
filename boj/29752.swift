var N = Int(readLine()!)!
var num = readLine()!
var nnum = num.split(separator: " ")
var result: Int = 0
for (idx, num) in nnum.enumerated() {
    let rnum = Int(num)!
    if idx == 0 {
        result = rnum
    } else {
        if rnum > result {
            result = rnum
        }
    }
}
print(result)