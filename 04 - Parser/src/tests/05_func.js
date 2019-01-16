function showMessage() { // Простая функция.
  alert( 'Привет всем присутствующим!' );
}
showMessage();

function showMessage() {
  var message = 'Привет, я - Вася!'; // локальная переменная
  alert(message);
}
showMessage();

var i;
function count(a, b) {
  for (i = 0; i < 3; i++) {
    var j = i * 2;
  }
  alert(i);
  alert(j);
}

function checkAge(age) {
  if (age > 18) {
    return true;
  } else {
    return confirm('Родители разрешили?');
  }
}
var age = prompt('Ваш возраст?');

if (checkAge(age)) {
  alert( 'Доступ разрешен' );
} else {
  alert( 'В доступе отказано' );
}

function pow(x, n) {
  var result = x;
  for (i = 1; i < n; i++) {
    result *= x;
  }
  return result;
}

function pow1(x, n) {
  if (n != 1) {
    return x * pow1(x, n - 1);
  } else {
    return x;
  }
}