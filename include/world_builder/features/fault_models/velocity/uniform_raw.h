/*
  Copyright (C) 2018-2024 by the authors of the World Builder code.

  This file is part of the World Builder.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License as published
   by the Free Software Foundation, either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef WORLD_BUILDER_FEATURES_FAULT_MODELS_VELOCITY_UNIFORM_RAW_H
#define WORLD_BUILDER_FEATURES_FAULT_MODELS_VELOCITY_UNIFORM_RAW_H


#include "world_builder/features/fault_models/velocity/interface.h"
#include "world_builder/features/feature_utilities.h"


namespace WorldBuilder
{

  namespace Features
  {
    namespace FaultModels
    {
      namespace Velocity
      {
        /**
         * This class represents a subducting plate and can implement submodules
         * for velocity and composition. These submodules determine what
         * the returned velocity or composition of the velocity and composition
         * functions of this class will be.
         */
        class UniformRaw final: public Interface
        {
          public:
            /**
             * constructor
             */
            UniformRaw(WorldBuilder::World *world);

            /**
             * Destructor
             */
            ~UniformRaw() override final;

            /**
             * declare and read in the world builder file into the parameters class
             */
            static
            void declare_entries(Parameters &prm, const std::string &parent_name = "");

            /**
             * declare and read in the world builder file into the parameters class
             */
            void parse_entries(Parameters &prm) override final;


            /**
             * Returns a velocity based on the given position, depth in the model,
             * gravity and current velocity.
             */
            std::array<double,3> get_velocity(const Point<3> &position,
                                              const double depth,
                                              const double gravity,
                                              std::array<double,3> velocity,
                                              const double feature_min_depth,
                                              const double feature_max_depth,
                                              const WorldBuilder::Utilities::PointDistanceFromCurvedPlanes &distance_from_planes,
                                              const AdditionalParameters &additional_parameters) const override final;


          private:
            // uniform raw velocity submodule parameters
            double min_depth;
            double max_depth;
            std::array<double,3> velocity;
            Operations operation;

        };
      } // namespace Velocity
    } // namespace FaultModels
  } // namespace Features
} // namespace WorldBuilder

#endif
