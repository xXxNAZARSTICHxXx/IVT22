program N223j; //название программы
const n=1000; //максимально допустимый массив - ограничивающая константа
type massive=array[1..n] of integer; //собственный тип massive
var
a:massive; // присвоение с использованием собственного типа
k,e:integer; //k-позиция ПЕРВОГО отрицательного числа e-диапазон задействованного массива; 
procedure sizemassive(var e: integer);
begin
 write('Введите количество символов массива, которые вы хотите использовать: ');  
 readln(e);
end;

procedure fillmassive(var a:massive;var e:integer);
var
i:integer;
begin
  writeln('Заполните массив числами, вы выбрали ', e,' символов');
  for i:=1 to e do //цикл заполения задействованного диапазона массива
    readln(a[i]);
  if a[1]<=0 then begin //проверка на то,что первое число НЕ <1
    writeln('Условие задачи 223ж не соблюдается... ОШИБКА');
    exit;
end;
end;

procedure findminus(var k:integer;a:massive;e:integer);
var
i:integer;
turn:boolean;
begin
  i:=0;
  k:=0;
  turn:=false;
  while turn=false do begin //проверка на ПЕРВОЕ отрицательное число
    i:=i+1;
    k:=k+1; //расчет позиции отрицательного числа
    if a[i]<0 then
      turn:=true;
  end;

end;

procedure performtask(k:integer;a:massive);
var
i,noth:integer;
begin
 
  noth:=0;
  for i:=1 to k do //поиск удвоенных нечетных
    if (a[i] mod 2 = 0) then begin //удвоение превращаем в обычное, проверяя его
    a[i]:=a[i] div 2; //делаем обычное число
    if(a[i] mod 2 = 1) then //...если оно нечетное
      noth:=noth+1; //отметить его в переменной noth
      end;
  writeln('Количество удвоенных нечетных до первого отрицательного числа: ', noth);
  end;
  
begin
  
  sizemassive(e);
  fillmassive(a,e);
  findminus(k,a,e);
  performtask(k,a);
  
end.