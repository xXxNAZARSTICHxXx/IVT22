import 'package:flutter_bloc/flutter_bloc.dart';
part 'counter_state.dart';

class CounterCubit extends Cubit<CounterState> {
  CounterCubit() : super(CounterValue(0)); // Начальное состояние

  // Метод увеличения значения
  void increment() {
    final currentValue = (state as CounterValue).value;
    emit(CounterValue(currentValue + 1));
  }

  // Метод уменьшения значения
  void decrement() {
    final currentValue = (state as CounterValue).value;
    emit(CounterValue(currentValue - 1));
  }
}