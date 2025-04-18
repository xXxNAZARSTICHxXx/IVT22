import '../models/photo_model.dart';

abstract class RoverState {}

class RoverLoadingState extends RoverState {}

class RoverLoadedState extends RoverState {
  final List<Photo> photos;

  RoverLoadedState(this.photos);
}

class RoverErrorState extends RoverState {}