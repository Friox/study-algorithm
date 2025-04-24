let input = 'XXXX....XXX.....XX'
let length = input.length
let flag = true
input = input.replaceAll('XXXX', 'AAAA')
input = input.replaceAll('XX', 'BB')
for (let i = 0; i < length; i++) {
	if (input[i] == 'X') {
		flag = false
		break;
	}
}
console.log(flag ? input : -1)