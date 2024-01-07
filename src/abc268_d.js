/*
 * @type: checker
 * @author: Milmon <milmon@qq.com>
 * @date: 2024-01-07
 */

// NOTE: There is an issue with the testdata output file provided by Official AtCoder,
//       which has been fixed on the HydroOJ official website.

const fs = require('fs')
const input = fs.readFileSync('in').toString().trim()
const output = fs.readFileSync('user_out').toString().trim()
const answer = fs.readFileSync('answer').toString().trim()

if (answer === '-1') {
  if (output === '-1') console.error(`ok Correct`);
  else console.error('wrong answer Wrong Answer');
  process.exit(0)
}

if (output === '-1') {
  console.error('wrong answer Wrong Answer');
  process.exit(0)
}

const strings = input.split('\n').map((x) => x.trim())

const n = +strings[0].split(' ')[0]
const m = +strings[0].split(' ')[1]

if (
  output.length < 3 || output.length > 16
  || output.startsWith('_') || output.endsWith('_')
) console.error('wrong answer Wrong Answer');
else {
  const strs = output.split('_').filter((x) => x).sort((x, y) => x < y ? -1 : 1)
  let strs2 = []
  for (let i = 1; i <= n; i++)strs2.push(strings[i])
  strs2 = strs2.sort((x, y) => x < y ? -1 : 1)
  for (let i = 1; i <= n; i++)
    if (strs2[i] != strs[i]) {
      console.error('wrong answer Wrong Answer');
      process.exit(0)
    }
  for (let i = n + 1; i <= n + m; i++)
    if (output === strings[i]) {
      console.error('wrong answer Wrong Answer');
      process.exit(0)
    }
  console.error(`ok Correct`);
}