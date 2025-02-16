// Copyright (c) 2022 PaddlePaddle Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "paddle2onnx/mapper/tensor/bitwise_and.h"

namespace paddle2onnx {
REGISTER_MAPPER(bitwise_and, BitWiseAndMapper)

int32_t BitWiseAndMapper::GetMinOpset(bool verbose) {
  constexpr int op_version = 18;
  Logger(verbose, op_version) << RequireOpset(op_version) << std::endl;
  return op_version;
}


void BitWiseAndMapper::Opset18() {
  auto x_info = GetInput("X");
  auto y_info = GetInput("Y");
  auto out_info = GetOutput("Out");
  
  auto output = helper_->MakeNode("BitwiseAnd", {x_info[0].name, y_info[0].name}, {out_info[0].name});
}
}  // namespace paddle2onnx
