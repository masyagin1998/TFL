top: // labelled statement with break.
for(i=0; i<10; i++) {
  for(j=0; j<15; j++) {
    if (i==5 && j==5) break top;
  }
}
alert(j+i); // 10

kek: // labelled statement with continue.
for(i=0; i<10; i++) {
  for(j=0; j<10; j++) {
    if (i==j) continue kek;
    alert(i, j)
  }
}

function pow(a, b) { // При включенном режиме отладки в браузере на debugger программа будет останавливаться.
  alert(a);
  debugger;
  alert(b);
}

var a = 5; // with позволяет работать в контекст объекта.
var obj = {
  a: 10
};
with(obj) {
  alert(a);
}