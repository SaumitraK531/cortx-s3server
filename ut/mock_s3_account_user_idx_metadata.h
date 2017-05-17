/*
 * COPYRIGHT 2017 SEAGATE LLC
 *
 * THIS DRAWING/DOCUMENT, ITS SPECIFICATIONS, AND THE DATA CONTAINED
 * HEREIN, ARE THE EXCLUSIVE PROPERTY OF SEAGATE TECHNOLOGY
 * LIMITED, ISSUED IN STRICT CONFIDENCE AND SHALL NOT, WITHOUT
 * THE PRIOR WRITTEN PERMISSION OF SEAGATE TECHNOLOGY LIMITED,
 * BE REPRODUCED, COPIED, OR DISCLOSED TO A THIRD PARTY, OR
 * USED FOR ANY PURPOSE WHATSOEVER, OR STORED IN A RETRIEVAL SYSTEM
 * EXCEPT AS ALLOWED BY THE TERMS OF SEAGATE LICENSES AND AGREEMENTS.
 *
 * YOU SHOULD HAVE RECEIVED A COPY OF SEAGATE'S LICENSE ALONG WITH
 * THIS RELEASE. IF NOT PLEASE CONTACT A SEAGATE REPRESENTATIVE
 * http://www.seagate.com/contact
 *
 * Original author:  Swapnil Belapurkar   <swapnil.belapurkar@seagate.com>
 * Original creation date: 02-May-2017
 */

#pragma once

#ifndef __S3_UT_MOCK_S3_ACCOUNT_USER_IDX_METADATA_H__
#define __S3_UT_MOCK_S3_ACCOUNT_USER_IDX_METADATA_H__

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <json/json.h>
#include <string>
#include "base64.h"
#include "s3_account_user_index_metadata.h"
#include "s3_datetime.h"
#include "s3_iem.h"
#include "s3_request_object.h"

class MockS3AccountUserIdxMetadata : public S3AccountUserIdxMetadata {
 public:
  MockS3AccountUserIdxMetadata(std::shared_ptr<S3RequestObject> req)
      : S3AccountUserIdxMetadata(req) {}
  MOCK_METHOD2(save, void(std::function<void(void)> on_success,
                          std::function<void(void)> on_failed));
  MOCK_METHOD2(load, void(std::function<void(void)> on_success,
                          std::function<void(void)> on_failed));
  MOCK_METHOD0(get_state, S3AccountUserIdxMetadataState());
  MOCK_METHOD0(load_successful, void());
  MOCK_METHOD0(load_failed, void());
  MOCK_METHOD1(from_json, int(std::string content));
};

#endif