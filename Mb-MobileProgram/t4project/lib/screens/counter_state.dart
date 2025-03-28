part of 'counter_cubit.dart';

// Абстрактный класс состояния
abstract class CounterState {}

// Конкретное состояние счетчика
class CounterValue extends CounterState {
  final int value;

  CounterValue(this.value);
}