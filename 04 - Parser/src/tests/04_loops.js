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
for (i = 1; i < 5; i++) {
  alert(i);
}

i = 0;
for (i = -5; i < 0; i++) alert(i);

i = 0;
for(;;) if (i++ < 5) break;