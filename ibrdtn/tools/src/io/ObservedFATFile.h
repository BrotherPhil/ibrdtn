/*
 * ObservedFATFile.h
 *
 * Copyright (C) 2013 IBR, TU Braunschweig
 *
 * Written-by: David Goltzsche <goltzsch@ibr.cs.tu-bs.de>
 *             Johannes Morgenroth <morgenroth@ibr.cs.tu-bs.de>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *  Created on: Sep 30, 2013
 */

#ifdef HAVE_LIBTFFS
#include "ObservedFile.h"
#include "FATFile.h"
#include <ibrcommon/data/File.h>

#ifndef OBSERVEDFATFILE_H_
#define OBSERVEDFATFILE_H_

namespace io
{
	class ObservedFATFile : public ObservedFile
	{
	public:
		ObservedFATFile(const ibrcommon::File &image_file, const std::string& file_path);
		virtual ~ObservedFATFile();

		virtual const ibrcommon::File& getImageFile() const;

		virtual int getFiles(std::list<ObservedFile*>& files);
		virtual std::string getPath() const;
		virtual bool exists();
		virtual std::string getBasename() const;
		virtual void update();

	private:
		io::FATFile _file;
		ibrcommon::File _image_file;
	};
}

#endif /* OBSERVEDFATFILE_H_ */
#endif /* HAVE_LIBTFFS*/
