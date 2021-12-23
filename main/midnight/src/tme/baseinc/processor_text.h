#ifndef _CTEXTPROCESSOR_H_INCLUDED_
#define _CTEXTPROCESSOR_H_INCLUDED_

#include <string.h>

#include "lomxtypes.h"
#include "info.h"

#define    MAX_STRING_BUFFERS    64
#define MAX_STRING_SIZE        512


namespace tme {

    using namespace chilli;
    using chilli::collections::c_ptr;
    
    class CStrBuf;
    
    //namespace processors {

        class mxtext
        {
        public:
            enum MODE_CASE {
                CASE_NONE=0,
                CASE_FIRST=1,
                CASE_UPPER=2,
                CASE_LOWER=3
            };
            
            enum ZERO_MODE {
                ZERO_NO=0,
                ZERO_NONE=1,
                ZERO_ZERO=2,
            };
            
        public:
            mxtext();
            virtual ~mxtext();

            std::string Format ( LPCSTR format, ... );

            LPCSTR SystemString ( u32 id );
            LPCSTR SystemStringById ( mxid id );
            mxid StringByName ( const std::string& name ) const;

            std::string CookedSystemString ( u32 id, const mxcharacter* character=NULL );
            std::string CookText ( std::string& input, const mxcharacter* character=NULL );
            std::string DescribePlural( u32 single, int number );
            std::string DescribeNumber ( int number, ZERO_MODE zeromode=ZERO_NO );

            virtual void Serialize ( chilli::lib::archive& ar );

            virtual std::string DecodeToken ( LPSTR token, const mxcharacter* character=NULL );
            virtual std::string HowMuchOfText( u32 number, LPSTR text1, LPSTR text2 ) ;
            virtual std::string DescribeNumberPart ( int number, ZERO_MODE zeromode=ZERO_NO )  ;
            virtual std::string DescribeEnergy ( u32 energy );
            virtual std::string DescribeFear ( u32 fear );
            virtual std::string DescribeCourage ( u32 courage );
            virtual std::string DescribeDespondent ( u32 despondent );
            virtual std::string DescribeReckless ( u32 reckless );
#if defined(_DDR_)
            virtual std::string DescribeTime ( u32 time );
#endif
            
            // character descriptions
            virtual std::string DescribeCharacterRecruitMen ( const mxcharacter* character, const mxstronghold* stronghold, u32 qty )  ;
            virtual std::string DescribeCharacterPostMen ( const mxcharacter* character, const mxstronghold* stronghold, u32 qty )  ;

            virtual std::string DescribeCharacterTime( const mxcharacter* character ) ;
            virtual std::string DescribeCharacterEnergy ( const mxcharacter* character ) ;
            virtual std::string DescribeCharacterCourage ( const mxcharacter* character ) ;
            virtual std::string DescribeCharacterFear ( const mxcharacter* character ) ;

            virtual std::string DescribeCharacterObject ( const mxcharacter* character )  ;
            virtual std::string DescribeCharacterDeath ( const mxcharacter* character )  ;
#if defined(_DDR_)
            virtual std::string DescribeCharacterDeath2 ( const mxcharacter* character )  ;
#endif
            virtual std::string DescribeCharacterBattle ( const mxcharacter* character ) ;
            virtual std::string DescribeCharacterArmy ( const mxcharacter* character ) ;
            virtual std::string DescribeCharacterTraits ( const mxcharacter* character ) ;
            virtual std::string DescribeCharacterFoe ( const mxcharacter* character ) ;
            virtual std::string DescribeCharacterLiege ( const mxcharacter* character ) ;
            virtual std::string DescribeCharacterLocation( const mxcharacter* character ) ;
            virtual std::string DescribeCharacterGroup ( const mxcharacter* character ) ;
#if defined(_DDR_)
            virtual std::string DescribeCharacterLoyalty ( const mxcharacter* character ) ;
            virtual std::string DescribeCharacterSees ( const mxcharacter* character ) ;
            virtual std::string DescribeCharacterInBattle ( const mxcharacter* character );
#endif

            // strongholds

            virtual std::string DescribeStronghold (const mxstronghold* stronghold) ;

            // army totals
            virtual std::string DescribeArmyTotal(const mxarmytotal* army) ;

            // location
            virtual std::string DescribeLocation( mxgridref loc) ;
#if defined(_DDR_)
            virtual std::string DescribeLocationWithPrep ( mxgridref loc, const mxcharacter* character );
#endif
            virtual std::string DescribeArea(u32 area) ;
            virtual std::string DescribeTerrainPlural(mxterrain_t terrain);
            virtual std::string DescribeTerrainSingularPlural(mxterrain_t terrain);

            // objects
            virtual std::string DescribeObject ( const mxobject* object );
#if defined(_DDR_)
            virtual std::string DescribeObjectLocation( mxobject* object);
            virtual std::string DescribeObjectWithPower ( const mxobject* object );
#endif


            // special strings
            virtual std::string SpecialStrings ( LPCSTR token, const mxcharacter* character );

        protected:
            void FillArrayFromSystemString( LPSTR array[], u32 id );
            void FillArrayFromSystemString( c_ptr& array, u32 id );

        public:
            mxgridref        loc;

            mxrace*            rinfo;
            mxgender*        ginfo;
            mxdirection*    dinfo;
            mxarea*            ainfo;
            mxterrain*        tinfo;
#if defined(_DDR_)
            mxobjectpower*  opinfo;
            mxobjecttype*   otinfo;
#endif
            const           mxobject*    oinfo;

#if defined(_DDR_)
            LPSTR            adverb_token[8];
#else
            LPSTR            adverb_token[9];
#endif
            LPSTR            number_token[30];
            LPSTR            fear_token[2];
            LPSTR            courage_token[2];
            LPSTR            energy_token[2];
            LPSTR            reckless_token[2];
            LPSTR            despondent_token[2];
#if defined(_DDR_)
            LPSTR            zero_token[3];
#endif
#if defined(_LOM_)
            LPSTR            zero_token[10];
#endif
            LPSTR            plural_tokens[4];

            c_ptr            traits_token;
            
            //u32                m_zerotype;
            
            MODE_CASE       m_case;

            
            int             last_number;
        protected:
            u32             m_cSystemStrings;
            c_str*          systemstrings;
            c_str*          systemcodes;
            c_str           emptyString;
        };
    //}
}








#endif //_CTEXTPROCESSOR_H_INCLUDED_
