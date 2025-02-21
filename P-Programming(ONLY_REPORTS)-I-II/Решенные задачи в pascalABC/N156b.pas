program N156b; //начало программы

const n=10; //обозначение константы n
type massive=array[1..n] of real; //введение собственного типа massive

var
a:massive; //обозачаем массив своим типом
z:real; //z-сумматор
i:integer; //i-позиция в массиве
Logic: boolean; //выключатель кода
Question: Char; //Ответ на "выключатель" 
Way: string; //way - путь файла для записи
YourFile: text; //YourFile - вывод в файл

begin
  Logic:=false; //выключатель в режим "включен"
  writeln('Напиши адрес для создания отчета:');
  Readln(way); //считывание адреса для записи файла
  Assign(YourFile, Way); //объявление пути файла
  if FileExists(Way)= False then Rewrite(YourFile) else Append(YourFile); //проверка на файл
  while logic = false do begin //если выключатель "включен"

    writeln('Введите 10 чисел (по константе): ');
    z:=0; //обнуляем сумматор
    readln(a[1]); //вводим первое число
    readln(a[2]); //вводим второе число
    for i:=3 to n do begin
      readln(a[i]); //вводим третье число
      z:=z+(a[i-2]+a[i-1]+a[i])*a[i-1]; //расчитываем по формуле из задания
    end;
    writeln(YourFile,'Ответ: ',z); //выписываем ответ
    Writeln('Хотите использовать программу еще раз? Y\N');
    Readln(Question); //считывает ответ при Y-выключатель включен, при N-выключатель выключен
    If question = 'N' then Logic:= True; //если выключатель выключен
    end;
  closefile(YourFile); //закрываем файл
end. //конец программы