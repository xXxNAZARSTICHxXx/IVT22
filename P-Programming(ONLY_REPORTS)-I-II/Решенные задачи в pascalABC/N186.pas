program N186; //название программы
const n=50; //максимально допустимый массив - ограничивающая константа
type massive=array[1..n] of real; //собственный тип massive
var
a:massive; //присвоение с использованием собственного типы
pros:real; //меременная всеобщего произведения
e:integer; //e-диапазон задействованного массива;

procedure sizemassive(var e: integer);
begin
 repeat
   writeln('Введите количество символов массива, которые вы хотите использовать,');  
   writeln('но это значение должно быть равно 50 или меньше: ');  
   readln(e);
 until e<51;
end;

procedure fillmassive(var a:massive;var e:integer);
var
i:integer;
queres:char;
begin
  writeln('Вы хотите заполнить массив самостоятельно или сделать это случайнымим числами от 1 до 9?'); //случайно или ручным способом
  writeln('Введите *H* для ручного заполнения или *R* для случайного заполения: ');
  readln(queres);
  if queres='H' then begin //Ручной способ заполнения
  writeln('Заполните массив числами, вы выбрали ', e,' символов');
  for i:=1 to e do
    readln(a[i]);
  end
  else if queres='R' then begin //Случайный способ заполнения [0;9]
    randomize;
    write('Ваш случайный массив: ');
    for i:=1 to e do begin
    a[i]:=random(9);
    write(a[i],' ');
    end;
  end
  else //если будет введено что-то другое, то программа оборвется
    exit;
end;

procedure performtask(a:massive;e:integer);
var
i,f:integer;
pros:real;
begin
  f:=1; //присвоение факториала 1 для вычислений
  pros:=1; //присвоение множителя 1 для вычислений
  for i:=1 to e do begin //цикл проверки условия заполнений
    f:=f*i; //вычисление факториала
    if (i+1<a[i]) and (a[i]<f) then //проверка условия по заданию
    pros:=pros*a[i]; //уножение множителя, если условие = правда
  end;
  writeln;
  writeln('Твоя велечина произведения членов равна: ', pros); //вывод в 'окно вывода'
end;

begin

  sizemassive(e);
  fillmassive(a,e);
  performtask(a,e);
  
end.
