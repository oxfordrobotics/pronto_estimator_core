#pragma once
#include <Eigen/Dense>
#include "pronto_estimator_core/rbis_update_interface.hpp"
#include "pronto_estimator_core/definitions.hpp"
#include "pronto_estimator_core/mav_state_est.hpp"

namespace MavStateEst {

//enum ScanMatchingMode {
//    MODE_POSITION, MODE_POSITION_YAW, MODE_VELOCITY, MODE_VELOCITY_YAW, MODE_YAW
//};

class ScanMatcherModule {
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
public:
        enum ScanMatchingMode {
            MODE_POSITION, MODE_POSITION_YAW, MODE_VELOCITY, MODE_VELOCITY_YAW, MODE_YAW
        };
    ScanMatcherModule();

  ScanMatcherModule(const ScanMatchingMode& mode,
                    const Eigen::VectorXi& z_indices,
                    const Eigen::MatrixXd& cov_scan_match);

  RBISUpdateInterface * processMessage(const PoseMeasurement * msg,
                                       MavStateEstimator* state_estimator);
protected:
    ScanMatchingMode mode;
    Eigen::VectorXi z_indices;
    Eigen::MatrixXd cov_scan_match;
};

}