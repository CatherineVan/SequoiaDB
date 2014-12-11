/*******************************************************************************


   Copyright (C) 2011-2014 SequoiaDB Ltd.

   This program is free software: you can redistribute it and/or modify
   it under the term of the GNU Affero General Public License, version 3,
   as published by the Free Software Foundation.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warrenty of
   MARCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
   GNU Affero General Public License for more details.

   You should have received a copy of the GNU Affero General Public License
   along with this program. If not, see <http://www.gnu.org/license/>.

   Source File Name = pmdProcessor.hpp

   Dependencies: N/A

   Restrictions: N/A

   Change Activity:
   defect Date        Who Description
   ====== =========== === ==============================================
          01/12/2014  Lin Youbin  Initial Draft

   Last Changed =

*******************************************************************************/

#ifndef PMD_PROCESSOR_HPP_
#define PMD_PROCESSOR_HPP_

#include "pmd.hpp"
#include "rtnCB.hpp"
#include "dmsCB.hpp"
#include "pmdProcessorBase.hpp"

namespace engine
{
   class _DataProcessor : public _IProcessor
   {
      public:
         _DataProcessor() ;
         virtual ~_DataProcessor() ;

      public:
         virtual INT32           processMsg( MsgHeader *msg, 
                                             SDB_DPSCB *dpsCB,
                                             rtnContextBuf &contextBuff, 
                                             INT64 &contextID, 
                                             INT32 &startPos ) ;

         virtual const CHAR *    getName() ;

      public:
         virtual INT32           attachSession( ISession *pSession ) ;
         virtual void            detachSession() ;

      protected:
         INT32                   _onMsgReqMsg( MsgHeader * msg ) ;
         INT32                   _onUpdateReqMsg( MsgHeader * msg, 
                                                  SDB_DPSCB *dpsCB ) ;
         INT32                   _onInsertReqMsg( MsgHeader * msg ) ;
         INT32                   _onQueryReqMsg( MsgHeader * msg,
                                                 SDB_DPSCB *dpsCB,
                                                 _rtnContextBuf &buffObj,
                                                 INT32 &startingPos,
                                                 INT64 &contextID ) ;
         INT32                   _onDelReqMsg( MsgHeader * msg, 
                                               SDB_DPSCB *dpsCB ) ;
         INT32                   _onGetMoreReqMsg( MsgHeader * msg,
                                                   rtnContextBuf &buffObj,
                                                   INT32 &startingPos,
                                                   INT64 &contextID ) ;
         INT32                   _onKillContextsReqMsg( MsgHeader *msg ) ;
         INT32                   _onSQLMsg( MsgHeader *msg, INT64 &contextID ) ;
         INT32                   _onTransBeginMsg () ;
         INT32                   _onTransCommitMsg ( SDB_DPSCB *dpsCB ) ;
         INT32                   _onTransRollbackMsg ( SDB_DPSCB *dpsCB ) ;
         INT32                   _onAggrReqMsg( MsgHeader *msg, 
                                                INT64 &contextID ) ;
         INT32                   _onOpenLobMsg( MsgHeader *msg, 
                                                SDB_DPSCB *dpsCB,
                                                SINT64 &contextID,
                                                rtnContextBuf &buffObj ) ;
         INT32                   _onWriteLobMsg( MsgHeader *msg ) ;
         INT32                   _onReadLobMsg( MsgHeader *msg,
                                                rtnContextBuf &buffObj ) ;
         INT32                   _onCloseLobMsg( MsgHeader *msg ) ;
         INT32                   _onRemoveLobMsg( MsgHeader *msg, 
                                                  SDB_DPSCB *dpsCB ) ;

      protected:
         _ISession *             _pSession ;
         _pmdEDUCB *             _pEDUCB ;
         _SDB_KRCB *             _pKRCB ;
         _SDB_DMSCB *            _pDMSCB ;
         _SDB_RTNCB *            _pRTNCB ;
   } ;
}

#endif  /*PMD_PROCESSOR_HPP_*/
