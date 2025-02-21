program N201a; //название программы
const n=100; //максимально допустимый массив - ограничивающая константа
type massive=array[1..n] of real; //собственный тип massive
var
a:massive; // присвоение с использованием собственного типа
i,e:integer; //i-цикл; e-диапазон задействованного массива; max - максимаальное число;

procedure sizemassive(var e: integer);
begin
 repeat
   writeln('Введите количество символов массива, которые вы хотите использовать,');  
   writeln('но это количество не должно превышать 100: ');
   readln(e);
 until e<101;
end;

procedure fillmassive(var a:massive;e:integer);
var
i:integer;
queres:char;
begin
  writeln('Вы хотите заполнить массив самостоятельно или сделать это случайнымим числами от -999 до 999?'); //случайно или ручным способом
  writeln('Введите *H* для ручного заполнения или *R* для случайного заполения: ');
  readln(queres);
  if queres='H' then begin //Ручной способ заполнения
  writeln('Заполните массив числами, вы выбрали ', e,' символов');
  for i:=1 to e do
    readln(a[i]);
  end
  else if queres='R' then begin //Случайный способ заполнения [-999;999]
    randomize;
    writeln('Ваш случайный массив: ');
    for i:=1 to e do begin
    a[i]:=random(1999)-1000;
    write(a[i],' ');
    end;
  end
  else //если будет введено что-то другое, то программа оборвется
    exit;
end;

procedure countmax(a:massive;e:integer);
var
i:integer;
max:real;
begin
max:=a[1];
for i:=1 to e do
  if max<a[i] then
    max:=a[i];
writeln;
writeln('Максимальное число массива: ', max);
end;

begin
  sizemassive(e);
  fillmassive(a,e);
  countmax(a,e); //вывод максимального числа
end.