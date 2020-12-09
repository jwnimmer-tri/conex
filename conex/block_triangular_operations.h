#pragma once
#include <vector>
#include "conex/triangular_matrix_workspace.h"
#include <Eigen/Dense>

struct BlockTriangularOperations {
  static void ApplyBlockInverseInPlace(const TriangularMatrixWorkspace& L,
                                       Eigen::VectorXd* b);
  static void ApplyBlockInverseOfTransposeInPlace(
      const TriangularMatrixWorkspace& L, Eigen::VectorXd* b);
  static void BlockCholeskyInPlace(TriangularMatrixWorkspace* mat);
  static void BlockLDLTInPlace(
      TriangularMatrixWorkspace* mat,
      std::vector<Eigen::LDLT<Eigen::Ref<Eigen::MatrixXd>>>* factorization);
  static void ApplyBlockInverseOfMTranspose(
      const TriangularMatrixWorkspace& mat,
      const std::vector<Eigen::LDLT<Eigen::Ref<Eigen::MatrixXd>>> factorization,
      Eigen::VectorXd* y);

  static void ApplyBlockInverseOfMD(
      const TriangularMatrixWorkspace& mat,
      const std::vector<Eigen::LDLT<Eigen::Ref<Eigen::MatrixXd>>> factorization,
      Eigen::VectorXd* y);

  static void SolveInPlaceLDLT(
      const TriangularMatrixWorkspace& mat,
      const std::vector<Eigen::LDLT<Eigen::Ref<Eigen::MatrixXd>>> factorization,
      Eigen::VectorXd* y) {
    ApplyBlockInverseOfMD(mat, factorization, y);
    ApplyBlockInverseOfMTranspose(mat, factorization, y);
  }
};
