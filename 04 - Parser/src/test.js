var i = 0; // Тест цикла do-While.
do {
  alert(i);
  i++;
} while (i < 3);

var i = 0; // Тест цикла While.
while (i < 3) {
  alert( i );
  i++;
}

i = 0;
var j = 0;

top:
while(i<10) {
  while(j<15) {
    if (i==5 && (j==5)) break top;
    j += 1
  }
  i++
}
alert(j+i);

var userName = 'Вася'; // Тест функции с нулевым кол-вом аргументов.
function showMessage() {
  var message = 'Привет, я ' + userName;
  alert(message);
}
showMessage();

function showMessage(from, text) { // Тест функции с двумя аргументами.
  from = '**' + from + '**';
  alert( from + ': ' + text );
}

var from = "Маша";
showMessage(from, "Привет");
alert( from );

function pow(x, n) { // Тест рекурсивной функции.
  if (n != 1) {
    return x * pow(x, n - 1);
  } else {
    return x;
  }
}
alert(pow(2, 3));

alert((1 * 5) + 5 >> 2 * (1 ^ 3 | 4 & 5))